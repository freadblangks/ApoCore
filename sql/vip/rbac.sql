insert into `rbac_permissions` (`id`, `name`) values('1005','debuff');
insert into `rbac_permissions` (`id`, `name`) values('1006','bank');
insert into `rbac_permissions` (`id`, `name`) values('1007','repair');
insert into `rbac_permissions` (`id`, `name`) values('1008','resettalents');
insert into `rbac_permissions` (`id`, `name`) values('1009','taxi');
insert into `rbac_permissions` (`id`, `name`) values('1010','home');
insert into `rbac_permissions` (`id`, `name`) values('1011','capital');
insert into `rbac_permissions` (`id`, `name`) values('1012','vip');

insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1005');
insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1006');
insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1007');
insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1008');
insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1009');
insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1010');
insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1011');
insert into `rbac_linked_permissions` (`id`, `linkedId`) values('195','1012');


insert into `rbac_default_permissions` (`secId`, `permissionId`) values('9','1005');
insert into `rbac_default_permissions` (`secId`, `permissionId`) values('10','1006');
insert into `rbac_default_permissions` (`secId`, `permissionId`) values('11','1007');
insert into `rbac_default_permissions` (`secId`, `permissionId`) values('12','1008');
insert into `rbac_default_permissions` (`secId`, `permissionId`) values('13','1009');
insert into `rbac_default_permissions` (`secId`, `permissionId`) values('14','10010');
insert into `rbac_default_permissions` (`secId`, `permissionId`) values('15','10011');
insert into `rbac_default_permissions` (`secId`, `permissionId`) values('16','10012');