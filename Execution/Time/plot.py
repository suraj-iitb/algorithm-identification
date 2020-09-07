import os
import numpy as np 
from matplotlib import pyplot as plt
import sys

# seperate plots
if sys.argv[1] == '1':
    for d1 in os.listdir('Result'):
        if d1 != 'quick':
            for file in os.listdir('Result/'+d1):
                if file == d1+'_run1_processed':
                    with open('Result/'+d1+'/'+file, 'r') as f:
                        x = []
                        y = []
                        for line in f:
                            line = line.strip().split('\t')
                            if len(line) != 0:
                                x.append(int(line[0]))
                                y.append(float(line[1]))
                                
                        plt.scatter(x, y, label=d1+" sort")
                        plt.xlabel('n')
                        plt.ylabel('T (ms)')
                        plt.legend()
                        plt.savefig('Figures/' + d1 + '.png')
                        plt.clf()

# combine based on complexity
if sys.argv[1] == '2':
    # n*logn
    for d1 in ['heap', 'merge']:
        for file in os.listdir('Result/'+d1):
            if file == d1+'_run1_processed':
                with open('Result/'+d1+'/'+file, 'r') as f:
                    x = []
                    y = []
                    for line in f:
                        line = line.strip().split('\t')
                        if len(line) != 0:
                            x.append(int(line[0]))
                            y.append(float(line[1]))
                            
                    plt.scatter(x, y, label=d1+" sort")
                    plt.xlabel('n')
                    plt.ylabel('T (ms)')
                    plt.legend()
    plt.savefig('Figures/nlogn.png')
    plt.clf()

    # n*n
    for d1 in ['bubble', 'insertion', 'selection']:
        for file in os.listdir('Result/'+d1):
            if file == d1+'_run1_processed':
                with open('Result/'+d1+'/'+file, 'r') as f:
                    x = []
                    y = []
                    for line in f:
                        line = line.strip().split('\t')
                        if len(line) != 0:
                            x.append(int(line[0]))
                            y.append(float(line[1]))
                            
                    plt.scatter(x, y, label=d1+" sort")
                    plt.xlabel('n')
                    plt.ylabel('T (ms)')
                    plt.legend()
    plt.savefig('Figures/nn.png')
    plt.clf()


# combine all complexity
if sys.argv[1] == '3':
    for d1 in os.listdir('Result'):
        if d1 != 'quick':
            for file in os.listdir('Result/'+d1):
                if file == d1+'_run1_processed':
                    with open('Result/'+d1+'/'+file, 'r') as f:
                        x = []
                        y = []
                        for line in f:
                            line = line.strip().split('\t')
                            if len(line) != 0:
                                x.append(int(line[0]))
                                y.append(float(line[1]))
                                
                        plt.scatter(x, y, label=d1+" sort")
                        plt.xlabel('n')
                        if sys.argv[2] == 'log':
                            plt.ylabel('log T (ms)')
                            plt.yscale("log")
                        else:
                            plt.ylabel('T (ms)')
                        plt.legend()
    if sys.argv[2] == 'log':
        plt.savefig('Figures/all(log-scale).png')
    else:
        plt.savefig('Figures/all.png')
    plt.clf()

# different y axis
if sys.argv[1] == '4':
    # common work
    color_list = ['black', 'grey']
    count = 0
    color = 'tab:red'
    fig, ax1 = plt.subplots()
    ax1.set_xlabel('n')
    ax1.set_ylabel('T (ms)', color=color)

    # n*logn
    for d1 in ['heap', 'merge']:
        for file in os.listdir('Result/'+d1):
            if file == d1+'_run1_processed':
                with open('Result/'+d1+'/'+file, 'r') as f:
                    x = []
                    y = []
                    for line in f:
                        line = line.strip().split('\t')
                        if len(line) != 0:
                            x.append(int(line[0]))
                            y.append(float(line[1]))
                            
                    ax1.scatter(x, y, label=d1+" sort", color=color_list[count])
                    ax1.tick_params(axis='y', labelcolor=color)
                    count += 1

    # common work
    color = 'tab:blue'
    ax2 = ax1.twinx()
    ax2.set_ylabel('T (ms)', color=color)

    # n*n
    for d1 in ['bubble', 'insertion', 'selection']:
        for file in os.listdir('Result/'+d1):
            if file == d1+'_run1_processed':
                with open('Result/'+d1+'/'+file, 'r') as f:
                    x = []
                    y = []
                    for line in f:
                        line = line.strip().split('\t')
                        if len(line) != 0:
                            x.append(int(line[0]))
                            y.append(float(line[1]))
                            
                    ax2.scatter(x, y, label=d1+" sort")
                    ax2.tick_params(axis='y', labelcolor=color)
                    
    fig.tight_layout()
    ax1.legend()
    ax2.legend()
    plt.savefig('Figures/all(diff-y-axis).png')
    plt.clf()
