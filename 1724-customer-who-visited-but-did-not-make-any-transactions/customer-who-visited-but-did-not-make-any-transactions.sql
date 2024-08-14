-- select v.customer_id, COUNT(v.visit_id) as count_no_trans
-- from Visits v left join Transactions t
-- on v.visit_id = t.visit_id
-- where t.amount IS NULL
-- group by v.customer_id;
select customer_id,count(*) as count_no_trans
from Visits
where visit_id not in(select visit_id from Transactions)
group by customer_id;