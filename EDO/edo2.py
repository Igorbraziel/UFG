# EDO: x’’ + 0.1 * x’ + x + 5 * x³ = 0.8
import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# Parâmetros
delta = 0.1
alpha = 1
beta = 5
A = 0.8
phi = 0

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

# Condições iniciais e o intervalo de tempo
y0 = [1.0, 1.0]           # Condições iniciais: x(0) = 1, v(0) = 1
t_span = (0, 50)          # Simular de t=0 até t=50
t_eval = np.linspace(0, 50, 2000)  # 2000 pontos igualmente espaçados para avaliar

# Resolver a equação usando solve_ivp (método RK45)
sol = solve_ivp(duffing, t_span, y0, t_eval=t_eval, method='RK45')

# sol.t: vetor de tempos

# sol.y[0]: posição x(t)

# sol.y[1]: velocidade v(t)

# gráficos da solução:
plt.figure(figsize=(12, 4))

# Gráfico de x(t)
plt.subplot(1, 2, 1)
plt.plot(sol.t, sol.y[0])
plt.title('Solução x(t)')
plt.xlabel('Tempo (t)')
plt.ylabel('Deslocamento (x)')

# Espaço de fase x vs v
plt.subplot(1, 2, 2)
plt.plot(sol.y[0], sol.y[1])
plt.title('Espaço de fase: x vs v')
plt.xlabel('x(t)')
plt.ylabel('v(t)')

plt.tight_layout()
plt.show()

# x(t): mostra o comportamento do sistema ao longo do tempo.

# x vs v: mostra o espaço de fase, ou seja, como a posição 
# e a velocidade se relacionam — isso revela se o sistema é
# periódico, amortecido ou caótico.



