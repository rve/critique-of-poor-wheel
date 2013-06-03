
primes [] = []
primes (x:xs) = x : primes (filter (\n->n`mod`x/=0) xs)


maxFactors n xs = filter (\x->n`mod`x==0) xs

maxF n [] = []
maxF 1 xs = []
maxF n (x:xs) = if n`mod`x == 0
                then x:(maxF (n`div`x) xs)
                else
                        (maxF n xs)

main = do
       maxF 600851475143 (primes [2..10^12])