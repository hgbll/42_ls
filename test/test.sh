ls -lRat $1 > tmp1
../ft_ls -lRat $1 > tmp2
diff tmp1 tmp2 > diff
