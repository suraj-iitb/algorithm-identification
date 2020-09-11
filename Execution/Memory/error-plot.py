import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

## Variables ####
y_scale = False
output = 'all_sd.png'
metric = 'sd'
################

index = {'10000': 0, '50000':1, '100000':2}

raw_mean = {'n': [10000, 50000, 100000],
        'bubble': [0,0,0],
        'insertion': [0,0,0],
        'selection': [0,0,0],
        'heap': [0,0,0],
        'quick': [0,0,0],
        'merge': [0,0,0]}

raw_sd = {'n': [10000, 50000, 100000],
        'bubble': [0,0,0],
        'insertion': [0,0,0],
        'selection': [0,0,0],
        'heap': [0,0,0],
        'quick': [0,0,0],
        'merge': [0,0,0]}

raw_ci = {'n': [10000, 50000, 100000],
        'bubble': [0,0,0],
        'insertion': [0,0,0],
        'selection': [0,0,0],
        'heap': [0,0,0],
        'quick': [0,0,0],
        'merge': [0,0,0]}

for d1 in os.listdir('Results'):
    if d1 != 'quick-iter':
        for file in os.listdir('Results/'+d1):
            if file.endswith('stats.csv'):
                with open('Results/'+d1+'/'+file) as f:
                    for line in f:
                        line = line.strip()
                        if line != '':
                            line = line.split(',')
                            if line[0] in list(index.keys()):
                                raw_mean[d1][index[line[0]]] = float(line[1])
                                raw_sd[d1][index[line[0]]] = float(line[2])
                                raw_ci[d1][index[line[0]]] = float(line[4])

df = pd.DataFrame(raw_mean, columns = ['n', 'bubble', 'insertion', 'selection', 'heap', 'quick', 'merge'])

# Setting the positions and width for the bars
pos = list(range(len(df['n'])))
width = 0.15
    
# Plotting the bars
fig, ax = plt.subplots(figsize=(10,5))

# Create a bar with bubble data,
# in position pos,
if metric == 'sd':
    error = raw_sd['bubble']
else:
    error = raw_ci['bubble']

plt.bar(pos, 
        #using df['bubble'] data,
        df['bubble'],
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='blue', 
        # with label the first value in n
        # label=df['n'][0],
        yerr=error,
        capsize=5)

# Create a bar with insertion data,
# in position pos + some width buffer,
if metric == 'sd':
    error = raw_sd['insertion']
else:
    error = raw_ci['insertion']

plt.bar([p + width for p in pos], 
        #using df['insertion'] data,
        df['insertion'],
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='#F78F1E', 
        # with label the second value in n
        # label=df['n'][1],
        yerr=error,
        capsize=5)

# Create a bar with selection data,
# in position pos + some width buffer,
if metric == 'sd':
    error = raw_sd['selection']
else:
    error = raw_ci['selection']

plt.bar([p + width*2 for p in pos], 
        #using df['selection'] data,
        df['selection'], 
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='#AAC222', 
        # with label the third value in n
        # label=df['n'][2],
        yerr=error,
        capsize=5) 

# Create a bar with quick data,
# in position pos + some width buffer,
if metric == 'sd':
    error = raw_sd['quick']
else:
    error = raw_ci['quick']

plt.bar([p + width*3 for p in pos], 
        #using df['quick'] data,
        df['quick'], 
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='red', 
        # with label the third value in first_name
        # label=df['n'][4],
        yerr=error,
        capsize=5)

# Create a bar with heap data,
# in position pos + some width buffer,
if metric == 'sd':
    error = raw_sd['heap']
else:
    error = raw_ci['heap']

plt.bar([p + width*4 for p in pos], 
        #using df['heap'] data,
        df['heap'], 
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='black', 
        # with label the third value in first_name
        # label=df['n'][3],
        yerr=error,
        capsize=5)

# Create a bar with merge data,
# in position pos + some width buffer,
if metric == 'sd':
    error = raw_sd['merge']
else:
    error = raw_ci['merge']

plt.bar([p + width*5 for p in pos], 
        #using df['merge'] data,
        df['merge'], 
        # of width
        width, 
        # with alpha 0.5
        alpha=0.5, 
        # with color
        color='grey', 
        # with label the third value in first_name
        # label=df['n'][5],
        yerr=error,
        capsize=5)

# scale
if y_scale:
    ax.set_yscale('log')

# Set the y axis label
if y_scale:
    ax.set_ylabel('log (time)')
else:
    ax.set_ylabel('Time')

ax.set_xlabel('Input Size')

# Set the chart's title
ax.set_title('Runtime Statistics')

# Set the position of the x ticks
ax.set_xticks([p + 2.5 * width for p in pos])

# Set the labels for the x ticks
ax.set_xticklabels(df['n'])

# Setting the x-axis and y-axis limits
# plt.xlim(min(pos)-width, max(pos)+width*4)
# plt.ylim([0, max(df['pre_score'] + df['mid_score'] + df['post_score'])] )

# Adding the legend and showing the plot
plt.legend(['Bubble', 'Insertion', 'Selection', 'Quick', 'Heap', 'Merge'], loc='upper left')
plt.grid()
plt.savefig('Figures/'+output)