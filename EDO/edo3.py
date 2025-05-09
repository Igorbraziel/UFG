# EDO:  x’’ + 2 * x’ + x = 2 * cos(t) 
import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# Parâmetros
delta = 0.2
alpha = -1
beta = 1
A = 0.3
phi = 1.2

epsilon1 = 0
epsilon2 = 0.05
epsilon3 = 0.1

def duffing(t, y):
  """
  A função duffing(t, y) recebe o tempo t e o vetor y com duas variáveis:
  y[0] = posição x
  y[1] = velocidade v = dx/dt
  Retorna as derivadas [dx/dt, dv/dt].
  """
  x, v = y
  dxdt = v
  dvdt = -delta * v - alpha * x - beta * x**3 + A * np.cos(phi * t)
  return [dxdt, dvdt]

# Condições iniciais de cada PVI
y0 = [1.0 + epsilon1, 2.0 + epsilon1]  # Condições iniciais: x(0) = 1 + epsilon, v(0) = 2 + epsilon
y1 = [1.0 + epsilon2, 2.0 + epsilon2]  # Condições iniciais: x(0) = 1 + epsilon, v(0) = 2 + epsilon
y2 = [1.0 + epsilon3, 2.0 + epsilon3]  # Condições iniciais: x(0) = 1 + epsilon, v(0) = 2 + epsilon
t_span = (0, 200)          # Simular de t=0 até t=200
t_eval = np.linspace(0, 200, 2000)  # 2000 pontos igualmente espaçados para avaliar

# Resolver a equação usando solve_ivp (método RK45)
sol_pvi_0 = solve_ivp(duffing, t_span, y0, t_eval=t_eval, method='RK45')
sol_pvi_1 = solve_ivp(duffing, t_span, y1, t_eval=t_eval, method='RK45')
sol_pvi_2 = solve_ivp(duffing, t_span, y2, t_eval=t_eval, method='RK45')

# sol.t: vetor de tempos

# sol.y[0]: posição x(t)

# sol.y[1]: velocidade v(t)

# gráficos da solução:
plt.figure(figsize=(12, 12))

# Gráfico de PVI 0
plt.subplot(3, 1, 1)
plt.plot(sol_pvi_0.t, sol_pvi_0.y[0])
plt.title('Solução x(t)')
plt.xlabel('Tempo (t)')
plt.ylabel('Deslocamento (x)')

# Gráfico de PVI 1
plt.subplot(3, 1, 2)
plt.plot(sol_pvi_1.t, sol_pvi_1.y[0])
plt.title('Solução x(t)')
plt.xlabel('Tempo (t)')
plt.ylabel('Deslocamento (x)')

# Gráfico de PVI 2
plt.subplot(3, 1, 3)
plt.plot(sol_pvi_2.t, sol_pvi_2.y[0])
plt.title('Solução x(t)')
plt.xlabel('Tempo (t)')
plt.ylabel('Deslocamento (x)')

plt.tight_layout()
plt.show()

# x(t): mostra o comportamento do sistema ao longo do tempo.

# x vs v: mostra o espaço de fase, ou seja, como a posição 
# e a velocidade se relacionam — isso revela se o sistema é
# periódico, amortecido ou caótico.



