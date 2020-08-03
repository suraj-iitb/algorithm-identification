def similarity(lines, lines_count, algo1, algo2, algo1_algo1_processed, algo1_algo2_processed):
    for i in range(lines_count):
        
        line = lines[i].strip().split(',')
        
        code1 = line[0]
        per1 = float(line[1][:-1])
        code2 = line[2]
        per2 = float(line[3][:-1])
        
        # print(code1, per1, code2, per2)

        if algo1 in code1 and algo1 in code2:

            sum1 = 0
            sum2 = 0

            count1 = 0
            count2 = 0

            max1 = -999
            max2 = -999

            for j in range(lines_count):
            
                line_b = lines[j].strip().split(',')
            
                code1_b = line_b[0]
                per1_b = float(line_b[1][:-1])
                code2_b = line_b[2]
                per2_b = float(line_b[3][:-1])
            
                if algo1 in code1_b and algo1 in code2_b:
                    
                    if code1 not in algo1_algo1_processed:
                        if code1 == code1_b:
                            sum1 += per1_b
                            count1 += 1

                            if max1 < per1_b:
                                max1 = per1_b

                        elif code1 == code2_b:
                            sum1 += per2_b
                            count1 += 1

                            if max1 < per2_b:
                                max1 = per2_b

                    if code2 not in algo1_algo1_processed:
                        if code2 == code1_b:
                            sum2 += per1_b
                            count2 += 1

                            if max2 < per1_b:
                                max2 = per1_b

                        elif code2 == code2_b:
                            sum2 += per2_b
                            count2 += 1

                            if max2 < per2_b:
                                max2 = per2_b
                                
            if count1 > 0:
                avg1 = sum1 / count1
                algo1_algo1_processed[code1] = {'avg': avg1, 'max': max1}
                # if code1 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum1, count1, avg1)
            if count2 > 0:
                avg2 = sum2 / count2
                algo1_algo1_processed[code2] = {'avg': avg2, 'max': max2}
                # if code2 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum2, count2, avg2)

        if (algo1 in code1 and algo2 in code2) or (algo2 in code1 and algo1 in code2):

            sum1 = 0
            sum2 = 0

            count1 = 0
            count2 = 0

            max1_i = -999
            max2_i = -999

            for j in range(lines_count):
            
                line_b = lines[j].strip().split(',')
            
                code1_b = line_b[0]
                per1_b = float(line_b[1][:-1])
                code2_b = line_b[2]
                per2_b = float(line_b[3][:-1])
            
                if (algo1 in code1_b and algo2 in code2_b) or (algo2 in code1_b and algo1 in code2_b):
                    
                    if (algo1 in code1 and code1 not in algo1_algo2_processed):
                        if code1 == code1_b:
                            sum1 += per1_b
                            count1 += 1

                            if max1_i < per1_b:
                                max1_i = per1_b

                        elif code1 == code2_b:
                            sum1 += per2_b
                            count1 += 1

                            if max1_i < per2_b:
                                max1_i = per2_b

                    if (algo1 in code2 and code2 not in algo1_algo2_processed):
                        if code2 == code1_b:
                            sum2 += per1_b
                            count2 += 1

                            if max2_i < per1_b:
                                max2_i = per1_b

                        elif code2 == code2_b:
                            sum2 += per2_b
                            count2 += 1

                            if max2_i < per2_b:
                                max2_i = per2_b

            if count1 > 0:
                avg1 = sum1 / count1
                algo1_algo2_processed[code1] = {'avg': avg1, 'max': max1_i}
                # if code1 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum1, count1, avg1)
            if count2 > 0:
                avg2 = sum2 / count2
                algo1_algo2_processed[code2] = {'avg': avg2, 'max':max2_i}
                # if code2 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum2, count2, avg2)

def hypothesis(suffix, algo1_algo1_processed, algo1_algo2_processed, algo1_max, algo1_min, algo1_avg, algo2_max, algo2_min, algo2_avg):
    with open('hypothesis1'+suffix+'.txt', 'w') as h1:
        with open('hypothesis2'+suffix+'.txt', 'w') as h2:
            with open('hypothesis3'+suffix+'.txt', 'w') as h3:
                with open('hypothesis4'+suffix+'.txt', 'w') as h4:
                    with open('hypothesis5'+suffix+'.txt', 'w') as h5:

                        for code in algo1_algo1_processed:

                            # hypothesis 1
                            avg_with_algo1 = algo1_algo1_processed[code]['avg']

                            try:
                                avg_with_algo2 = algo1_algo2_processed[code]['avg']
                            except KeyError:
                                avg_with_algo2 = 0
                            
                            if avg_with_algo1 >= algo1_max and avg_with_algo2 <= algo2_min:
                                h1.write(code+'\tValid\n')
                            else:
                                h1.write(code+'\tInvalid\n')

                            # hypothesis 2
                            max_with_algo1 = algo1_algo1_processed[code]['max']

                            try:
                                max_with_algo2 = algo1_algo2_processed[code]['max']
                            except KeyError:
                                max_with_algo2 = 0
                            
                            if max_with_algo1 >= algo1_max and max_with_algo2 <= algo2_min:
                                h2.write(code+'\tValid\n')
                            else:
                                h2.write(code+'\tInvalid\n')

                            # hypothesis 3
                            if max_with_algo1 >= algo1_avg and max_with_algo2 <= algo2_avg:
                                h3.write(code+'\tValid\n')
                            else:
                                h3.write(code+'\tInvalid\n')

                            # hypothesis 4                   
                            if avg_with_algo1 >= algo1_min and avg_with_algo2 <= algo2_min:
                                h4.write(code+'\tValid\n')
                            else:
                                h4.write(code+'\tInvalid\n')

                            # hypothesis 5                 
                            if max_with_algo1 >= algo1_min and max_with_algo2 <= algo2_min:
                                h5.write(code+'\tValid\n')
                            else:
                                h5.write(code+'\tInvalid\n')


def metric_calculate(suffix1, suffix2):
    for i in range(1,6):
        with open('hypothesis' + str(i) + suffix1 + '.txt', 'r') as h1:
            tp = 0
            fp = 0
            lines = [line.strip() for line in h1]
            for line in lines:
                line = line.split('\t')
                # print(line[1])
                if line[1] == 'Valid':
                    # print(line[1])
                    tp +=1
                if line[1] == 'Invalid':
                    # print(line[1])
                    fp +=1

        with open('hypothesis' + str(i) + suffix2 + '.txt', 'r') as h1:
            tn = 0
            fn = 0
            lines = [line.strip() for line in h1]
            for line in lines:
                line = line.split('\t')
                # print(line[1])
                if line[1] == 'Valid':
                    # print(line[1])
                    tn +=1
                if line[1] == 'Invalid':
                    # print(line[1])
                    fn +=1

        recall = tp / (tp +fp) * 100
        precision = tp / (tp +fn) * 100
        try:
            f1 = 2*((precision*recall)/(precision+recall))
        except Exception:
            f1 = 0.0

        print('Recall for hypothesis ' + str(i) + ' is: ', str(round(recall,2)) + ' %')
        print('Precision for hypothesis ' + str(i) + ' is: ', str(round(precision,2)) + ' %')
        print('F1 Score for hypothesis ' + str(i) + ' is: ', str(round(f1,2)) + ' %')
   



################################################### Main ###################################################
b_min = 24
b_max = 53
b_avg = 30

i_min = 17
i_max = 66
i_avg = 27

bubble = 'Data/Bubble/Dump/bubble'
insertion = 'Data/Insertion/Dump/insertion'

bubble_bubble_processed = {}
bubble_insertion_processed = {}
insertion_insertion_processed = {}
insertion_bubble_processed = {}

with open('results.csv', 'r') as f:

    lines = [line.strip() for line in f]
    lines_count = len(lines)

    # print(lines)
    # print(bubble_processed['Data/BubbleSort/Dump/bubble-1673563.cpp'])
    # print(bubble_insertion_processed['Data/BubbleSort/Dump/bubble-1673563.cpp'])

    # Bubble
    algo1_algo1_processed = {}
    algo1_algo2_processed = {}
    similarity(lines, lines_count, bubble, insertion, algo1_algo1_processed, algo1_algo2_processed)
    bubble_bubble_processed = algo1_algo1_processed
    bubble_insertion_processed = algo1_algo2_processed
    hypothesis("bubble", bubble_bubble_processed, bubble_insertion_processed, b_max, b_min, b_avg, i_max, i_min, i_avg)

    # Insertion
    algo1_algo1_processed = {}
    algo1_algo2_processed = {}
    similarity(lines, lines_count, insertion, bubble, algo1_algo1_processed, algo1_algo2_processed)
    insertion_insertion_processed = algo1_algo1_processed
    insertion_bubble_processed = algo1_algo2_processed
    hypothesis("insertion", bubble_bubble_processed, bubble_insertion_processed, i_max, i_min, i_avg, b_max, b_min, b_avg)

    # Metric Calculation
    metric_calculate("bubble", "insertion")