/*	$Id$ */
/*
 * Copyright (c) 2015, 2017 Kristaps Dzonsons <kristaps@bsd.lv>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef KCGIXML_H
#define KCGIXML_H

#if !defined(__BEGIN_DECLS)
#  ifdef __cplusplus
#  define       __BEGIN_DECLS           extern "C" {
#  else
#  define       __BEGIN_DECLS
#  endif
#endif
#if !defined(__END_DECLS)
#  ifdef __cplusplus
#  define       __END_DECLS             }
#  else
#  define       __END_DECLS
#  endif
#endif

struct	kxmlreq {
	struct kreq	  *req;
	const char *const *elems;
	size_t		   elemsz;
	size_t	 	   stack[128];
	size_t		   stackpos;
};

__BEGIN_DECLS

enum kcgi_err	 kxml_close(struct kxmlreq *);
enum kcgi_err	 kxml_open(struct kxmlreq *, struct kreq *, const char *const *, size_t);
enum kcgi_err	 kxml_push(struct kxmlreq *, size_t);
enum kcgi_err	 kxml_pushattrs(struct kxmlreq *, size_t, ...);
enum kcgi_err	 kxml_pushnull(struct kxmlreq *, size_t);
enum kcgi_err	 kxml_pushnullattrs(struct kxmlreq *, size_t, ...);
enum kcgi_err	 kxml_pop(struct kxmlreq *);
enum kcgi_err	 kxml_popall(struct kxmlreq *);
enum kcgi_err	 kxml_putc(struct kxmlreq *, char);
enum kcgi_err	 kxml_puts(struct kxmlreq *, const char *);
enum kcgi_err	 kxml_write(const char *, size_t, void *);

__END_DECLS

#endif
