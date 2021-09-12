SELECT
  COUNT(*) as Total,
  ROUND(COUNT(*) / 226.43, 2) as Percent,
  name_en, name_cn
FROM have 
JOIN Categories
ON cate_id = id
GROUP BY name_en
HAVING Percent >= 1
ORDER BY Total DESC