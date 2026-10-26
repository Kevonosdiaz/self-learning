SELECT b.N,
CASE
    WHEN b.P IS NULL THEN "Root"
    WHEN b.N IN (SELECT P from BST) THEN "Inner"
    ELSE "Leaf"
END
FROM BST as b
ORDER BY b.N;
