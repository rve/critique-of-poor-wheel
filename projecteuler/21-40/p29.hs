import Data.List
test = [a^b| a<-[2..5], b<-[2..5]]
pre = [a^b| a<-[2..100], b<-[2..100]]
ans xs = length $ nub xs

main = do
     putStr $ show $ ans pre