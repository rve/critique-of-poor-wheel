encode :: (Eq a) => [a] -> [(a,Int)]
encode [] = []
encode (x:xs) = (x, length (filter (x==) xs) + 1) : encode (filter (x/=) xs)
