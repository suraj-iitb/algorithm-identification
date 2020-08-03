def similarity(lines, lines_count):
    for i in range(lines_count):
        
        line = lines[i].strip().split(',')
        
        code1 = line[0]
        per1 = float(line[1][:-1])
        code2 = line[2]
        per2 = float(line[3][:-1])
        
        # print(code1, per1, code2, per2)

        if bubble in code1 and bubble in code2:

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
            
                if bubble in code1_b and bubble in code2_b:
                    
                    if code1 not in bubble_processed:
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

                    if code2 not in bubble_processed:
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
                bubble_processed[code1] = {'avg': avg1, 'max': max1}
                # if code1 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum1, count1, avg1)
            if count2 > 0:
                avg2 = sum2 / count2
                bubble_processed[code2] = {'avg': avg2, 'max': max2}
                # if code2 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum2, count2, avg2)

        if (bubble in code1 and insertion in code2) or (insertion in code1 and bubble in code2):

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
            
                if (bubble in code1_b and insertion in code2_b) or (insertion in code1_b and bubble in code2_b):
                    
                    if (bubble in code1 and code1 not in bubble_insertion_processed):
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

                    if (bubble in code2 and code2 not in bubble_insertion_processed):
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
                bubble_insertion_processed[code1] = {'avg': avg1, 'max': max1_i}
                # if code1 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum1, count1, avg1)
            if count2 > 0:
                avg2 = sum2 / count2
                bubble_insertion_processed[code2] = {'avg': avg2, 'max':max2_i}
                # if code2 == 'Data/BubbleSort/Dump/bubble-1673563.cpp':
                #     print(sum2, count2, avg2)

def hypothesis():
    with open('hypothesis1.txt', 'w') as h1:
        with open('hypothesis2.txt', 'w') as h2:
            with open('hypothesis3.txt', 'w') as h3:
                with open('hypothesis4.txt', 'w') as h4:
                    with open('hypothesis5.txt', 'w') as h5:

                        for bubble in bubble_processed:

                            # hypothesis 1
                            avg_with_bubble = bubble_processed[bubble]['avg']

                            try:
                                avg_with_insertion = bubble_insertion_processed[bubble]['avg']
                            except KeyError:
                                avg_with_insertion = 0
                            
                            if avg_with_bubble >= b_max and avg_with_insertion <= i_min:
                                h1.write(bubble+'\tValid\n')
                            else:
                                h1.write(bubble+'\tInvalid\n')

                            # hypothesis 2
                            max_with_bubble = bubble_processed[bubble]['max']

                            try:
                                max_with_insertion = bubble_insertion_processed[bubble]['max']
                            except KeyError:
                                max_with_insertion = 0
                            
                            if max_with_bubble >= b_max and max_with_insertion <= i_min:
                                h2.write(bubble+'\tValid\n')
                            else:
                                h2.write(bubble+'\tInvalid\n')

                            # hypothesis 3
                            if max_with_bubble >= b_avg and max_with_insertion <= i_avg:
                                h3.write(bubble+'\tValid\n')
                            else:
                                h3.write(bubble+'\tInvalid\n')

                            # hypothesis 4                   
                            if avg_with_bubble >= b_min and avg_with_insertion <= i_min:
                                h4.write(bubble+'\tValid\n')
                            else:
                                h4.write(bubble+'\tInvalid\n')

                            # hypothesis 5                 
                            if max_with_bubble >= b_min and max_with_insertion <= i_min:
                                h5.write(bubble+'\tValid\n')
                            else:
                                h5.write(bubble+'\tInvalid\n')


def metric_calculate():
    with open('hypothesis1.txt', 'r') as h1:
        valid = 0
        invalid = 0
        lines = [line.strip() for line in h1]
        for line in lines:
            line = line.split('\t')
            # print(line[1])
            if line[1] == 'Valid':
                # print(line[1])
                valid +=1
            if line[1] == 'Invalid':
                # print(line[1])
                invalid +=1
        val_per = valid / (valid +invalid) * 100
        print('% Recall for hypothesis 1 is: ', val_per)
    with open('hypothesis2.txt', 'r') as h2:
        valid = 0
        invalid = 0
        lines = [line.strip() for line in h2]
        for line in lines:
            line = line.split('\t')
            # print(line[1])
            if line[1] == 'Valid':
                # print(line[1])
                valid +=1
            if line[1] == 'Invalid':
                # print(line[1])
                invalid +=1
        val_per = valid / (valid +invalid) * 100
        print('% Recall for hypothesis 2 is: ', val_per)
    with open('hypothesis3.txt', 'r') as h3:
        valid = 0
        invalid = 0
        lines = [line.strip() for line in h3]
        for line in lines:
            line = line.split('\t')
            # print(line[1])
            if line[1] == 'Valid':
                # print(line[1])
                valid +=1
            if line[1] == 'Invalid':
                # print(line[1])
                invalid +=1
        val_per = valid / (valid +invalid) * 100
        print('% Recall for hypothesis 3 is: ', val_per)
    with open('hypothesis4.txt', 'r') as h4:
        valid = 0
        invalid = 0
        lines = [line.strip() for line in h4]
        for line in lines:
            line = line.split('\t')
            # print(line[1])
            if line[1] == 'Valid':
                # print(line[1])
                valid +=1
            if line[1] == 'Invalid':
                # print(line[1])
                invalid +=1
        val_per = valid / (valid +invalid) * 100
        print('% Recall for hypothesis 4 is: ', val_per)
    with open('hypothesis5.txt', 'r') as h5:
        valid = 0
        invalid = 0
        lines = [line.strip() for line in h5]
        for line in lines:
            line = line.split('\t')
            # print(line[1])
            if line[1] == 'Valid':
                # print(line[1])
                valid +=1
            if line[1] == 'Invalid':
                # print(line[1])
                invalid +=1
        val_per = valid / (valid +invalid) * 100
        print('% Recall for hypothesis 5 is: ', val_per)



################################################### Main ###################################################
b_min = 24
b_max = 53
b_avg = 30

i_min = 17
i_max = 66
i_avg = 27

bubble = 'Data/Bubble/Dump/bubble'
insertion = 'Data/Insertion/Dump/insertion'

bubble_processed = {}
bubble_insertion_processed = {}
insertion_processed = {}
insertion_bubble_processed = {}

with open('results.csv', 'r') as f:

    lines = [line.strip() for line in f]
    lines_count = len(lines)

    # print(lines)
    # print(bubble_processed['Data/BubbleSort/Dump/bubble-1673563.cpp'])
    # print(bubble_insertion_processed['Data/BubbleSort/Dump/bubble-1673563.cpp'])

    similarity(lines, lines_count)
    hypothesis()
    metric_calculate()