(def fibs (lazy-cat [1 1] (map + fibs (rest fibs))))
(defn PE0002 [] (apply + (filter even? (take-while #(< % 4000001) fibs)))
(PE0002)
