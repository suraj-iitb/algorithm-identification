list_size = input()                                                                                                                                                                                         
list_str = input()                                                                                                                                                                                          
val_list = list(map(int, list_str.split()))                                                                                                                                                                 
                                                                                                                                                                                                            
def where_is_the_first_lowest_val(List):                                                                                                                                                                    
    return List.index(min(List))                                                                                                                                                                            
                                                                                                                                                                                                            
def swap(idx_num, lowest_val_index, List):                                                                                                                                                                  
    val = List[idx_num]                                                                                                                                                                                     
    List[idx_num] = List[lowest_val_index + idx_num]                                                                                                                                                        
    List[lowest_val_index + idx_num] = val                                                                                                                                                                  
                                                                                                                                                                                                            
swap_num = 0                                                                                                                                                                                                
for idx_num in range(0, int(list_size) - 1):                                                                                                                                                                
    unsorted_list = val_list[idx_num : int(list_size)]                                                                                                                                                      
    lowest_val_index = where_is_the_first_lowest_val(unsorted_list)                                                                                                                                         
    if val_list[idx_num] != val_list[lowest_val_index + idx_num]: swap(idx_num, lowest_val_index, val_list) ; swap_num += 1                                                                                 
                                                                                                                                                                                                            
str_list = list(map(str, val_list))                                                                                                                                                                         
str_list = ','.join(str_list).replace(',', ' ')                                                                                                                                                             
print(str_list)                                                                                                                                                                                             
print(swap_num)     
