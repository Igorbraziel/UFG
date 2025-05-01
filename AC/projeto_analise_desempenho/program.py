from typing import Dict, Any
import calculator

def is_float(string):
  try:
    float(string)
    return True
  except ValueError:
    return False
  
def is_int(string):
  try:
    int(string)
    return True
  except ValueError:
    return False

while True:  
  try:
    cpu_type = input('Digite o tipo de processador (ARM, x86): ')
    if cpu_type.lower() != "arm" and cpu_type.lower() != "x86":
      raise Exception("Tipo de Processador inválido!")
    cpu_type = cpu_type.upper()
    cpu_type = cpu_type.lower() if cpu_type[0].lower() == "x" else cpu_type  
    
    data_bus_width = input('Digite a largura do barramento de dados em bits (32, 64, 128): ')
    if not is_int(data_bus_width):
      raise Exception("A largura do barramento precisa ser um valor inteiro!")
    
    data_bus_width = int(data_bus_width)
    if data_bus_width not in [32, 64, 128]:
      raise Exception("A largura do barramento pode ser somente de 32, 64 ou 128 bits!")
    
    bus_frequency_unit = input('Digite a unidade desejada para a frequência do barramento (MHz, GHz): ')
    if bus_frequency_unit.lower() != "mhz" and bus_frequency_unit.lower() != "ghz":
      raise Exception("A unidade de frequência escolhida deve ser MHz ou GHz!")
    bus_frequency_unit = bus_frequency_unit[0:2].upper() + bus_frequency_unit[2].lower()
    
    bus_frequency_value = input(f'Digite o valor desejado para a frequência do barramento em ({bus_frequency_unit}): ')
    if not is_float(bus_frequency_value):
      raise Exception("O valor da frequência precisa ser numérico!")
    bus_frequency_value = float(bus_frequency_value)
    if bus_frequency_value <= 0:
      raise Exception("O valor da frequência precisa ser positivo!")
    
    bus_frequency = {
      "unit": bus_frequency_unit,
      "value": bus_frequency_value
    }
    
    number_of_devices = input('Digite o número de dispositivos conectados ao barramento: ')
    if not is_int(number_of_devices):
      raise Exception("O número de dispositivos precisa ser um número inteiro!")
    number_of_devices = int(number_of_devices)
    if number_of_devices <= 0:
      raise Exception("O número de dispositivos precisa ser positivo!")
    
    cycles_per_transfer = input('Digite a quantidade de ciclos por transferência: ')
    if not is_int(cycles_per_transfer):
      raise Exception("O número de ciclos por transferência precisa ser um número inteiro!")
    cycles_per_transfer = int(cycles_per_transfer)
    if cycles_per_transfer <= 0:
      raise Exception("O número de ciclos por transferência precisa ser positivo!")
    
    print("-" * 80)
    print("Taxa de Transferência Teórica:", round(calculator.transfer_rate(data_bus_width, bus_frequency), 2), "GB/s")
    print()
    
    print("Latência Estimada (considerando conflitos de acesso):", round(calculator.effective_latency(cycles_per_transfer, bus_frequency, number_of_devices), 2), "ns (nanossegundos)")
    print()
    
    print("Ciclos por Transferência:", cycles_per_transfer)
    print("Quanto maior o número de ciclos por transferência, menor é a taxa de transferência efetiva.")
    print("A CPU precisa esperar muitos ciclos para acessar a memória, isso reduz sua eficiência.")
    print("Mais ciclos por transferência implicam em maior latência na comunicação entre os dispositivos.")
    print()
    
    print("Largura de Banda Efetiva (considerando conflitos e atrasos):", round(calculator.effective_bandwidth(data_bus_width, bus_frequency, number_of_devices), 2), "GB/s")
    print("-" * 80)
    break
  except Exception as e: 
    print("-" * 80)
    print(e)
    print("-" * 80)
