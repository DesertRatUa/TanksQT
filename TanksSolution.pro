TEMPLATE = subdirs

SUBDIRS = Tanks UnitTest

Tanks.subdir = Tanks.pro

UnitTest.depends = Tanks
