import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
plt.rc('text', usetex=True)
plt.rc('font', family='serif')
plt.rc('text.latex', preamble=r'\usepackage{ gensymb }'
                              r'\usepackage[english,russian]{babel}')

data = pd.read_csv("data.txt", sep="\t")
x = data.iloc[:, 0]
y = data.iloc[:, 1]
x = x.to_numpy()
y = y.to_numpy()

plt.figure(figsize=(8, 6))
plt.scatter(x, y, marker="s", color="black", s=4)
plt.grid()
plt.title('push_back3')
plt.xlabel('ADD_NUMBER')
plt.ylabel('milliseconds')

plt.show()
