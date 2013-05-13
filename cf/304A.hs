triple n = [(a,b) | a <- [1..n], b <- [a..n], a*a + b*b <= n]
main = do
   n <- getLine
   putStr $ show $ length $ triple n
