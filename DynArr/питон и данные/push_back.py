import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
plt.rc('text.latex', preamble=r'\usepackage{ gensymb }'
                              r'\usepackage[english,russian]{babel}')

data = pd.read_csv("data.txt", sep="\t")
x = data.iloc[:, 0]
y1 = data.iloc[:, 1]
y2 = data.iloc[:, 2]
y3 = data.iloc[:, 3]
x = x.to_numpy()
y1 = y1.to_numpy()
y2 = y2.to_numpy()
y3 = y3.to_numpy()

plt.figure(figsize=(8, 6))
plt.scatter(x, y1, marker="s", color="black", s=4)
plt.scatter(x, y2, marker="s", color="blue", s=4)
plt.scatter(x, y3, marker="s", color="red", s=4)
plt.grid()
plt.legend(['push_back1', 'push_back2', 'push_back3'], loc="upper left")
plt.xlabel('ADD_NUMBER')
plt.ylabel('milliseconds')

plt.show()
