data Queue a = Empty | Start a (Queue a)

startQueue :: Queue a -> Maybe a
startQueue Empty = Nothing
startQueue (Start x y) = Just x

endQueue :: Queue a -> Maybe a
endQueue Empty = Nothing
endQueue (Start x Empty) = Just x
endQueue (Start x y) = endQueue y

pushQueue :: a -> Queue a -> Queue a
pushQueue a Empty = Start a Empty
pushQueue a (Start x y) = Start x (pushQueue a y)

popQueue :: Queue a -> Queue a 
popQueue Empty = Empty
popQueue(Start x Empty) = Empty
popQueue(Start x (Start y z)) = Start y z

isEmptyQueue :: Queue a -> Bool
isEmptyQueue Empty = True
isEmptyQueue (Start x y) = False

lenQueue :: Queue a -> Int
lenQueue Empty = 0
lenQueue (Start x y) = 1 + lenQueue y

whileNotEmpty :: (a -> b) -> Queue a -> [b]
whileNotEmpty _ Empty = []
whileNotEmpty f queue = map (f) (toList queue)

toList :: Queue a -> [a]
toList Empty = []
toList (Start x y) = [x]++toList y

toString Empty = ""
toString (Start x y) = show(x) ++ " " ++ toString y
  
instance (Show a) => Show (Queue a) where
    show queue = "[ " ++ toString queue ++ "]"
