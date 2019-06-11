
data Stack a = Empty | Top a (Stack a) 

push :: a -> Stack a -> Stack a
push a (Empty) = Top a (Empty)
push a (Top x y) = Top a (Top x y) 

pop :: Stack a -> Stack a
pop Empty = Empty
pop (Top x y) = y

height :: Stack a -> Int
height Empty = 0
height (Top x y) = 1 + height y

top :: Stack a -> Maybe a
top Empty = Nothing
top (Top x y) = Just x

isEmpty :: Stack a -> Bool
isEmpty Empty = True
isEmpty (Top x y) = False

instance (Show a) => Show (Stack a) where
    show stack = "Pilha de altura " ++ show (height stack) ++ " e topo " ++ (drop 5 (show(top stack))) 