SELECT COUNT(*) as Total, name_en
FROM have 
JOIN Categories
ON cate_id = id
GROUP BY name_en
ORDER BY Total DESC

SELECT COUNT(*) FROM Illustrations
