primes :: [Int] -> [Int]
primes [] = []
primes (x:xs) = x: (primes $ filter (\y->y`mod`x /= 0) xs)

top100 = take 100 (primes [2..])

myprimes n = filter (\y->n`mod`y == 0) top100

sqs :: Int -> Int -> Int --how many times the factor p is in n
sqs n p = if n`mod`p == 0
          then 1 + sqs (n`div`p) p
          else 0

cal :: Int -> Int -- How many factors ?
cal n = foldr (*) 1 ( map (\x->(sqs n x)+1) (myprimes n))


plist = zip [1..] (map (cal) [n*(n+1)`div`2 | n <- [1..]])

find' (x:xs) = if snd x >= 500
               then (fst x)*((fst x) + 1) `div` 2
               else find'  xs

main = do
       putStrLn $ show $ find' plist