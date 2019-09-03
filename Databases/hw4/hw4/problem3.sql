execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_update');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_insert');
execute procedure drop_if_exists('trigger', 'tr_DEPARTMENT_RATING_delete');

commit work;
set term #;
create trigger tr_DEPARTMENT_RATING_delete for DEPARTMENT_TESTER before DELETE
as
DECLARE old_rating varchar(5);
begin 
select RATING from f_rating(OLD.budget) into :old_rating;

update DEPARTMENT_RATING
set OCCURRENCES = OCCURRENCES - 1
where :old_rating = RATING;

end #

set term #;

commit work;

delete from DEPARTMENT_TESTER where DEPT_NO = '115';
delete from DEPARTMENT_TESTER where DEPT_NO = '672';

commit work;

select * from DEPARTMENT_RATING;

set term #;


