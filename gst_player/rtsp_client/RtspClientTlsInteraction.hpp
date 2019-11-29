#ifndef _rtsp_client_tls_interaction_h_
#define _rtsp_client_tls_interaction_h_

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>


G_BEGIN_DECLS

/* Inline class for providing a pre-configured client certificate */
typedef struct _RtspClientTlsInteraction RtspClientTlsInteraction;
typedef struct _RtspClientTlsInteractionClass RtspClientTlsInteractionClass;

static GType rtsp_client_tls_interaction_get_type(void) G_GNUC_CONST;

//This struct should contain instance variable for the subclass
struct _RtspClientTlsInteraction {
    GTlsInteraction parent_instance;
    GTlsCertificate *ca_cert, *cert_key;
    GTlsDatabase *database;
};

struct _RtspClientTlsInteractionClass {
    GTlsInteractionClass parent_class;
};

G_DEFINE_TYPE (RtspClientTlsInteraction, rtsp_client_tls_interaction, G_TYPE_TLS_INTERACTION) ;

GTlsInteractionResult rtsp_client_request_certificate(GTlsInteraction *interaction,
                                                      GTlsConnection *connection,
                                                      GTlsCertificateRequestFlags flags,
                                                      GCancellable *cancellable,
                                                      GError **error);

RtspClientTlsInteraction *
rtsp_client_tls_interaction_new(GTlsCertificate *cert_key, GTlsCertificate *ca_cert, GTlsDatabase *database);

static void
rtsp_client_tls_interaction_init(RtspClientTlsInteraction *interaction) {
}

static void
rtsp_client_tls_interaction_class_init(RtspClientTlsInteractionClass *klass) {
    GTlsInteractionClass *interaction_class = G_TLS_INTERACTION_CLASS (klass);
    interaction_class->request_certificate = rtsp_client_request_certificate;
}

G_END_DECLS

#endif


