with open('results.csv', 'r') as f:

    lines = [line.strip() for line in f]
    lines_count = len(lines)

    bubble_processed = {}
    
    # print(lines)

    for i in range(lines_count):
        
        line = lines[i].strip().split(',')
        
        code1 = line[0]
        per1 = float(line[1][:-1])
        code2 = line[2]
        per2 = float(line[3][:-1])
        
        # print(code1, per1, code2, per2)

        if 'Data/BubbleSort/Dump/bubble' in code1 and 'Data/BubbleSort/Dump/bubble' in code2:

            sum1 = 0
            sum2 = 0

            count1 = 0
            count2 = 0

            for j in range(lines_count):
            
                line_b = lines[j].strip().split(',')
            
                code1_b = line_b[0]
                per1_b = float(line_b[1][:-1])
                code2_b = line_b[2]
                per2_b = float(line_b[3][:-1])
            
                if 'Data/BubbleSort/Dump/bubble' in code1_b and 'Data/BubbleSort/Dump/bubble' in code2_b:
                    
                    if code1 not in bubble_processed:
                        if code1 == code1_b:
                            sum1 += per1_b
                            count1 += 1
                        elif code1 == code2_b:
                            sum1 += per2_b
                            count1 += 1

                    if code2 not in bubble_processed:
                        if code2 == code1_b:
                            sum2 += per1_b
                            count2 += 1
                        elif code2 == code2_b:
                            sum2 += per2_b
                            count2 += 1
            if count1 > 0:
                avg1 = sum1 / count1
                bubble_processed[code1] = avg1
                if code1 == 'Data/BubbleSort/Dump/bubble-1583262.cpp':
                    print(sum1, count1, avg1)
            if count2 > 0:
                avg2 = sum2 / count2
                bubble_processed[code2] = avg2
                if code2 == 'Data/BubbleSort/Dump/bubble-1583262.cpp':
                    print(sum2, count2, avg2)

            
            

    print(bubble_processed['Data/BubbleSort/Dump/bubble-1583262.cpp'])