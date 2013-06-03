cal xs = sum (map (\x->x^x) xs)

test = cal [1..3]
ans = cal [1..1000]