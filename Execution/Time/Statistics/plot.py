from matplotlib import pyplot as plt
import os

for d1 in os.listdir('Result'):
    for file in os.listdir('Result/'+d1):
        if file.endswith('stats'):
            x = []
            mean = []
            sd = []
            ci = []

            with open('Result/'+d1+'/'+file) as f:
                for line in f:
                    line = line.strip()
                    if line != '':
                        line = line.split(',')
                        x.append(int(line[0]))
                        mean.append(float(line[1]))
                        sd.append(float(line[2]))
                        ci.append(float(line[4]))
                print(x,mean,sd,ci)

                plt.scatter(x, mean, label="Mean Plot")
                # plt.plot(x, mean, '-ok')
                plt.xlabel('n')
                plt.ylabel('mean time(ms)')
                plt.legend()
                plt.savefig('Figures/' + d1 + '_mean.png')
                plt.clf()

                plt.scatter(x, sd, label="S.D. Plot")
                # plt.plot(x, sd)
                plt.xlabel('n')
                plt.ylabel('std dev.')
                plt.legend()
                plt.savefig('Figures/' + d1 + '_sd.png')
                plt.clf()

                plt.scatter(x, ci, label="CI Plot")
                # plt.plot(x, ci)
                plt.xlabel('n')
                plt.ylabel('margin of error for 95% CI')
                plt.legend()
                plt.savefig('Figures/' + d1 + '_ci.png')
                plt.clf()