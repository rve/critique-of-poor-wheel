generate :: Int -> [(Int, Int, Int)]
generate n =  [(a,b,c) | a <- [0..n], b <- [0..n], c <- [0..n]]
showit :: (Int, Int, Int) -> String
showit (a,b,c) = show a ++" " ++  show b ++" "++  show c
putit :: Int -> IO()
putit n = putStr (unlines (map showit (generate n)))

main = putit 10
