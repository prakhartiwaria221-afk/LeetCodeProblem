# Write your MySQL query statement below
UPDATE SALARY
SET sex = CASE
  WHEN sex = 'm' THEN 'f'
    ELSE 'm'
    END;