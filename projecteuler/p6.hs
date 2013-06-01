

main = do
       putStr $ show $ (sum [x^2 | x<-[1..100]] - (sum [1..100])^2)