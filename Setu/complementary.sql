SELECT COUNT(illust_id) as total, cate_id, name_en
FROM have
JOIN Categories
ON cate_id = id
WHERE name_cn ISNULL
GROUP BY cate_id
HAVING 4 <= total AND total < 6
ORDER BY total DESC

UPDATE Categories
SET name_cn = '手杖'
WHERE id = 563