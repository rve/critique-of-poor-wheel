

main = do
       putStr $ show $ foldr1 (\a b->(a*b)`div`(gcd a b))  [2..20]