ls -lRa $1 > tmp1
ls -lRa $1 > tmp2
diff tmp1 tmp2 > diff
rm tmp1
rm tmp2
