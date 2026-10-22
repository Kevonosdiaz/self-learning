SELECT co.Continent, FLOOR(AVG(ci.Population))
FROM COUNTRY co
JOIN CITY ci ON co.Code = ci.CountryCode
GROUP BY co.Continent;
