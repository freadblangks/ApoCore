--
SET @CGUID := 127340;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+29;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(1, @CGUID+00),
(1, @CGUID+01),
(1, @CGUID+02),
(1, @CGUID+03),
(1, @CGUID+04),
(1, @CGUID+05),
(1, @CGUID+06),
(1, @CGUID+07),
(1, @CGUID+08),
(1, @CGUID+09),
(1, @CGUID+10),
(1, @CGUID+11),
(1, @CGUID+12),
(1, @CGUID+13),
(1, @CGUID+14),
(1, @CGUID+15),
(1, @CGUID+16),
(1, @CGUID+17),
(1, @CGUID+18),
(1, @CGUID+19),
(1, @CGUID+20),
(1, @CGUID+21),
(1, @CGUID+22),
(1, @CGUID+23),
(1, @CGUID+24),
(1, @CGUID+25),
(1, @CGUID+26),
(1, @CGUID+27),
(1, @CGUID+28),
(1, @CGUID+29);