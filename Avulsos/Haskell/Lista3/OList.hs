data OList a = Empty | Node a (OList a) deriving (Eq, Ord)

infixr 5 >>>
(>>>) :: (Ord a) => a -> OList a -> OList a
a >>> Empty = Node a Empty
a >>> Node x y | a > x = Node x (a >>> y)
               | otherwise = Node a (Node x y)

hasKey :: (Ord a) => a -> OList a -> Bool
hasKey a Empty = False
hasKey a (Node x y) | x == a = True
                    | otherwise = hasKey a y

remKey :: (Ord a) => a -> OList a -> OList a
remKey a Empty = Empty
remKey a (Node x y) | x == a = y
                    | otherwise = (Node x (remKey a y))

key :: Int -> OList a -> Maybe a
key _ Empty = Nothing
key a (Node x y) = key' a (Node x y) 1

key' :: Int -> OList a -> Int -> Maybe a
key' _ Empty _ = Nothing
key' a (Node x y) z | z == a = Just x
                    | otherwise = key' a y (z+1)

toString Empty = ""
toString (Node x y) = show(x)++" "++ toString y

instance (Show a) => Show (OList a) where
     show list = "[ " ++ toString (list) ++ "]"
