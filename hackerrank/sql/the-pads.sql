SELECT CONCAT(occ.name, '(', LEFT(occ.occupation,1),')')
FROM OCCUPATIONS AS occ
ORDER BY occ.name ASC;
SELECT CONCAT("There are a total of ", COUNT(occ.occupation), " ", LOWER(occ.occupation), "s.")
FROM OCCUPATIONS AS occ
GROUP BY occ.occupation
ORDER BY COUNT(occ.occupation) ASC;
