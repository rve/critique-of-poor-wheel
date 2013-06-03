compress :: Eq a =>  [a] -> [a]
compress [] = []
compress (x:xs) = x : compress (filter (x/=) xs)