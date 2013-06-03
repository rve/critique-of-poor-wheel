import Data.Char
cal xs = sum $ map (\x->(ord x - ord '0')^5) xs
ansl = filter (\x->cal (show x) == x) [1..240000]
ans = (sum $ filter (\x->cal (show x) == x) [1..240000]) - 1