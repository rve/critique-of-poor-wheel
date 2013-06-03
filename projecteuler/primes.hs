primes [] = []
primes (x:xs) = x : primes (filter (\n->n`mod`x/=0) xs)

