def binary_search(input_array, value_to_find)
    left_index = 0
    right_index = input_array.size - 1
    while left_index <= right_index do
        middle_index = ((left_index + right_index)/2).floor
        if input_array[middle_index] < value_to_find
            left_index = middle_index+1
        elsif input_array[middle_index] > value_to_find
            right_index = middle_index-1
        else
            return middle_index
        end
    end
    return false
end