with open('../../Data/Bubble/Dump/code-id.txt') as b_ids:
    b_ids = [id.strip() for id in b_ids]
    b_ids_count = len(b_ids)

with open('../../Data/Insertion/Dump/code-id.txt') as i_ids:
    i_ids = [id.strip() for id in i_ids]
    i_ids_count = len(i_ids)

with open('../results.csv', 'r') as f:
    lines = [line.strip().split(',') for line in f]
    lines_count = len(lines)

# print(b_ids_count, i_ids_count, lines_count)

with open('vector.txt', 'w') as v:
    for id in b_ids:

        # print(id)
        id = 'bubble-'+ id
        cpm_id_list = {}

        for line in lines:
            if (line[0].split('/')[-1].split('.')[0]) == id:
                cpm_id_list[line[2].split('/')[-1].split('.')[0]] = line[1][:-1]
            if (line[2].split('/')[-1].split('.')[0]) == id:
                cpm_id_list[line[0].split('/')[-1].split('.')[0]] = line[3][:-1]

        print(id, cpm_id_list)

        op = id
        for i in b_ids:
            i = 'bubble-'+ i

            if i == id:
                op = op + ',' + '100'
            elif i in cpm_id_list.keys():
                op = op + ',' + cpm_id_list[i]
            else:
                op = op + ',' + '0'
        
        for i in i_ids:
            i = 'insertion-'+ i

            if i == id:
                op = op + ',' + '100'
            elif i in cpm_id_list.keys():
                op = op + ',' + cpm_id_list[i]
            else:
                op = op + ',' + '0'
        v.write(op+'\n')

    for id in i_ids:

        # print(id)

        id = 'insertion-'+ id
        cpm_id_list = {}

        for line in lines:
            if (line[0].split('/')[-1].split('.')[0]) == id:
                cpm_id_list[line[2].split('/')[-1].split('.')[0]] = line[1][:-1]
            if (line[2].split('/')[-1].split('.')[0]) == id:
                cpm_id_list[line[0].split('/')[-1].split('.')[0]] = line[3][:-1]

        print(id, cpm_id_list)

        op = id
        for i in b_ids:
            i = 'bubble-'+ i

            if i == id:
                op = op + ',' + '100'
            elif i in cpm_id_list.keys():
                op = op + ',' + cpm_id_list[i]
            else:
                op = op + ',' + '0'
        
        for i in i_ids:
            i = 'insertion-'+ i

            if i == id:
                op = op + ',' + '100'
            elif i in cpm_id_list.keys():
                op = op + ',' + cpm_id_list[i]
            else:
                op = op + ',' + '0'
        v.write(op+'\n')


        
        
    




