list_size = input()                                                                                                                                                                                         
list_str = input()                                                                                                                                                                                          
val_list = list(map(int, list_str.split()))                                                                                                                                                                 
                                                                                                                                                                                                            
def swap(first_idx, second_idx, val_list):                                                                                                                                                                  
    val = val_list[first_idx]                                                                                                                                                                               
    val_list[first_idx] = val_list[second_idx]                                                                                                                                                              
    val_list[second_idx] = val                                                                                                                                                                              
                                                                                                                                                                                                            
counter = 0                                                                                                                                                                                                 
while(True):                                                                                                                                                                                                
    finish = True                                                                                                                                                                                           
    for idx_num in range(0, int(list_size) - 1):                                                                                                                                                            
        if val_list[idx_num + 1] < val_list[idx_num]:                                                                                                                                                       
            swap(idx_num, idx_num + 1, val_list)                                                                                                                                                            
            finish = False                                                                                                                                                                                  
            counter += 1                                                                                                                                                                                    
    if finish == True: break                                                                                                                                                                                
                                                                                                                                                                                                            
print_list = ','.join(list(map(str, val_list)))                                                                                                                                                             
print_list = print_list.replace(',', ' ')                                                                                                                                                                   
print(print_list)                                                                                                                                                                                           
print(counter)             
