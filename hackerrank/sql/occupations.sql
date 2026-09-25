-- Use ROW_NUMBER() to align names of different occupations together
-- MAX is used to filter out 3 NULLs in same row for other occupations in that row
SELECT 
    MAX(CASE WHEN sub.occupation = "Doctor" THEN sub.name ELSE NULL END),
    MAX(CASE WHEN sub.occupation = "Professor" THEN sub.name ELSE NULL END),
    MAX(CASE WHEN sub.occupation = "Singer" THEN sub.name ELSE NULL END),
    MAX(CASE WHEN sub.occupation = "Actor" THEN sub.name ELSE NULL END)
FROM (
    SELECT name, occupation, ROW_NUMBER() OVER (PARTITION BY occupation ORDER BY name ASC) AS row_num
    FROM OCCUPATIONS
) AS sub
GROUP BY sub.row_num
ORDER BY sub.row_num;
