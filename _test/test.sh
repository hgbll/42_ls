../ft_ls -Rla $1 > my_ls
ls -Rla $1 > real_ls
diff my_ls real_ls > diff_result
