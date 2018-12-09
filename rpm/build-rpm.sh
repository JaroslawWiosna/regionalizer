#!/usr/bin/env bash

readonly BUILDROOT="build"
readonly TOPDIR="rpmbuild"
rpmbuild -vv -bb --buildroot "${BUILDROOT}" --define="_topdir ${TOPDIR}" "${TOPDIR}/SPECS/regionalizer.spec"
