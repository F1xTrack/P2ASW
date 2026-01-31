//========= Copyright  1996-2005, Valve Corporation, All rights reserved. ============//
#ifndef NETADR_H
#define NETADR_H
#ifdef _WIN32
#pragma once
#endif

#include "tier0/platform.h"
#include "tier0/basetypes.h"
#undef SetPort

typedef enum
{ 
	NA_NULL = 0,
	NA_LOOPBACK,
	NA_BROADCAST,
	NA_IP,
} netadrtype_t;

typedef struct netadr_s
{
public:
	netadr_s() { SetIP( 0 ); SetPort( 0 ); SetType( NA_IP ); }
	netadr_s( uint unIP, uint16 usPort ) { SetIP( unIP ); SetPort( usPort ); SetType( NA_IP ); }
	netadr_s( const char *pch ) { SetFromString( pch ); }
	void	Clear();

	void	SetType( netadrtype_t type );
	void	SetPort( unsigned short port );
	bool	SetFromSockadr(const struct sockaddr *s);
	void	SetIP(uint8 b1, uint8 b2, uint8 b3, uint8 b4);
	void	SetIP(uint unIP);
	void    SetIPAndPort( uint unIP, unsigned short usPort ) { SetIP( unIP ); SetPort( usPort ); }
	bool	SetFromString(const char *pch, bool bUseDNS = false );
	
	bool	CompareAdr (const netadr_s &a, bool onlyBase = false) const;
	bool	CompareClassBAdr (const netadr_s &a) const;
	bool	CompareClassCAdr (const netadr_s &a) const;

	netadrtype_t	GetType() const;
	unsigned short	GetPort() const;
	const char*		ToString( bool onlyBase = false ) const;
	void			ToString( char *pchBuffer, uint32 unBufferSize, bool onlyBase = false ) const;
	void			ToSockadr(struct sockaddr *s) const;
	unsigned int	GetIP() const;
	unsigned int	GetIPNetworkByteOrder() const;
	unsigned int	GetIPHostByteOrder() const;

	bool	IsLocalhost() const;
	bool	IsLoopback() const;
	bool	IsReservedAdr() const;
	bool	IsValid() const;
	bool	IsBaseAdrValid() const;

	void    SetFromSocket( int hSocket );

 	unsigned long addr_ntohl() const;
 	unsigned long addr_htonl() const;
	bool operator==(const netadr_s &netadr) const {return ( CompareAdr( netadr ) );}
	bool operator<(const netadr_s &netadr) const;

public:
	netadrtype_t	type;
	unsigned char	ip[4];
	unsigned short	port;
} netadr_t;

#endif