from typing import Dict, Any

def utilization_factor(number_of_devices: int) -> float:
  """Contention is caused when multiple devices attempt to use the bus at the same time. 
  The bus can only serve one transfer at a time, so others must wait, introducing latency.
  Args:
      number_of_devices (int): number of devices connected to bus
  Returns:
      float: percentage of each device is using the bus time.
  """
  return 1 / number_of_devices

def transfer_rate(data_bus_width: int, bus_frequency: Dict[str, Any]) -> float:
  """calculate the transfer rate: max data quantity
  that can be send in a time period
  Args:
      data_bus_width (int): number of bits
      bus_frequency (Dict[str, Any]): frequency containing the value and the unit (MHz or GHz)
      
  Returns:
      float: transfer rate (max bandwidth) measured in GB/s (GigaBytes per second)
  """
  number_of_bytes = data_bus_width / 8
  frequency = bus_frequency.get("value") if bus_frequency.get("unit").lower() == "ghz" else bus_frequency.get("value") / (10 ** 3)
  return number_of_bytes * frequency

def effective_bandwidth(data_bus_width: int, bus_frequency: Dict[str, Any], number_of_devices: int) -> float:
  """calculate the transfer rate: effective data quantity
  that can be send in a time period
  Args:
      data_bus_width (int): number of bits
      bus_frequency (Dict[str, Any]): frequency containing the value and the unit (MHz or GHz)
      number_of_devices (int): number of devices connected to bus
      
  Returns:
      float: effective bandwidth measured in GB/s (GigaBytes per second)
  """
  return transfer_rate(data_bus_width, bus_frequency) * utilization_factor(number_of_devices)

def latency(cycles_per_transfer: int, bus_frequency: Dict[str, Any]) -> float:
  """ calculate the estimated time between a data transfer request
  and the estimeted start of the data transfer
  Args:
      cycles_per_transfer (int): clock cycles per transfer
      bus_frequency (Dict[str, Any]): frequency containing the value and the unit (MHz or GHz)
  Returns:
      float: the estimeted time measured in ns (nanoseconds)
  """
  frequency = bus_frequency.get("value") * (10 ** 6) if bus_frequency.get("unit").lower() == "mhz" else bus_frequency.get("value") * (10 ** 9) 
  return (cycles_per_transfer / frequency) * (10 ** 9)

def effective_latency(cycles_per_transfer: int, bus_frequency: Dict[str, Any], number_of_devices: int) -> float:
  """ calculate the effective time between a data transfer request
  and the effective start of the data transfer
  on average a device waits (N - 1)/2 transfers before get access
  Args:
      cycles_per_transfer (int): clock cycles per transfer
      bus_frequency (Dict[str, Any]): frequency containing the value and the unit (MHz or GHz)
      number_of_devices (int): number of devices connected to bus
  Returns:
      float: the effective time measured in ns (nanoseconds)
  """
  base_latency = latency(cycles_per_transfer, bus_frequency)
  conflict_latency = ((number_of_devices - 1) / 2) * base_latency 
  return base_latency + conflict_latency
  



