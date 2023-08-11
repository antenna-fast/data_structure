

# input array: MSB, LSB
def calculate_neg(bite_arr):
    print("neg_arr: ", bite_arr)
    len_bite = len(bite_arr)
    full_scale = 2**len_bite
    # print(fs_val)

    pos_sum = 0
    for i in range(len(bite_arr)):  
        bite_val = bite_arr[len_bite - i -1]  # order: right -> left (LSB - MSB)
        print("bite pos: {}  {}".format(i, bite_val))
        pos_sum += bite_val * 2**i  # [MSB, LSB]

    neg_val = -(full_scale - pos_sum)

    return neg_val


if __name__ == "__main__":
    # define a bite vector
    # b8_neg_1 = [1, 1, 1, 1,  1, 1, 1, 1]  # -1
    b8_neg_2 = [1, 1, 1, 1, 1, 1, 1, 1,  1, 1, 1, 0]  # -2

    res = calculate_neg(b8_neg_2)
    print(res)
