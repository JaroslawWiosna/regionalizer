Name:	regionalizer	
Version:	1
Release:	1%{?dist}
Summary:	regio	

#Group:		
License:	MPL v2.0	
#URL:		
#Source0:	

#BuildRequires:	
#Requires:	

%description


%prep
#%setup -q


#%%build
#%%configure
#make %{?_smp_mflags}
#cp -r -p ../_builds/regionalizer %{_sourcedir}

%install
#make install DESTDIR=%{buildroot}
cp -r -p %{_sourcedir}/. %{buildroot}

%clean
#rm -rf %{_sourcedir}/*

%files
%doc



%changelog

