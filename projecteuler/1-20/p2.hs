fibs = 0 : 1 : zipWith (+) fibs (tail fibs)
main = 
       print $ sum $ filter (\x->x`mod`2==0 && x <=4000000) (take 50 fibs)
