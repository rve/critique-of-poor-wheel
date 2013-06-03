pack :: Eq a => [a] -> [[a]]
pack [] = []
pack (x:xs) = [[x] ++ (filter (x==) xs)] ++ (pack (filter (x/=) xs))
-- seems a good one compared to wiki solutions