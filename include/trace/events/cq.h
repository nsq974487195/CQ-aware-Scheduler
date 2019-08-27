#undef TRACE_SYSTEM
#define TRACE_SYSTEM cq 

#if !defined(_TRACE_CQ_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_CQ_H

//#include <linux/blkdev.h>
#include <linux/tracepoint.h>

TRACE_EVENT(cqdepth_cfq,

	TP_PROTO(int rq_sync_read, int rq_sync_write, int rq_async),

	TP_ARGS(rq_sync_read, rq_sync_write, rq_async),

	TP_STRUCT__entry(
		__field(int, sync)
		__field(int, sync_write)
		__field(int, async)
	),

	TP_fast_assign(
		__entry->sync = rq_sync_read;
		__entry->sync_write = rq_sync_write;
		__entry->async = rq_async;
	),

	TP_printk("CFQ : rq_sync : %d : rq_sync_write : %d : rq_async : %d", __entry->sync, __entry->sync_write, __entry->async)

);

TRACE_EVENT(cqoss_cfq,

	TP_PROTO(int rq_sync_read, int rq_sync_write, int rq_async),

	TP_ARGS(rq_sync_read, rq_sync_write, rq_async),

	TP_STRUCT__entry(
		__field(int, sync)
		__field(int, sync_write)
		__field(int, async)
	),

	TP_fast_assign(
		__entry->sync = rq_sync_read;
		__entry->sync_write = rq_sync_write;
		__entry->async = rq_async;
	),

	TP_printk("CFQ : rq_sync : %d : rq_sync_write : %d : rq_async : %d", __entry->sync, __entry->sync_write, __entry->async)

);

TRACE_EVENT(cqdepth_device,

	TP_PROTO(int rq_sync, int rq_sync_write, int rq_async),

	TP_ARGS(rq_sync, rq_sync_write, rq_async),

	TP_STRUCT__entry(
		__field(int, sync)
		__field(int, sync_write)
		__field(int, async)
	),

	TP_fast_assign(
		__entry->sync = rq_sync;
		__entry->sync_write = rq_sync_write;
		__entry->async = rq_async;
	),

	TP_printk("D/D : rq_sync : %d : rq_sync_write : %d : rq_async : %d", __entry->sync, __entry->sync_write, __entry->async)

);

TRACE_EVENT(cq_expire,

	TP_PROTO(int time_out, int queued, int dispatched),

	TP_ARGS(time_out, queued, dispatched),

	TP_STRUCT__entry(
		__field(int, timeout)
		__field(int, queued)
		__field(int, dispatched)
	),

	TP_fast_assign(
		__entry->timeout = time_out;
		__entry->queued = queued;
		__entry->dispatched = dispatched;
	),

	TP_printk("CFQQ expired : time_out : %d : queued : %d : dispatched : %d", __entry->timeout, __entry->queued, __entry->dispatched)

);

TRACE_EVENT(cq_thrt,

	TP_PROTO(int reason),

	TP_ARGS(reason),

	TP_STRUCT__entry(
		__field(int, reason)
	),

	TP_fast_assign(
		__entry->reason = reason;
	),

	TP_printk("CFQQ throttle : reason : %d", __entry->reason)

);

TRACE_EVENT(cq_maxdispatch,

	TP_PROTO(int max_dispatch, int dispatched),

	TP_ARGS(max_dispatch, dispatched),

	TP_STRUCT__entry(
		__field(int, max_dispatch)
		__field(int, dispatched)
	),

	TP_fast_assign(
		__entry->max_dispatch = max_dispatch;
		__entry->dispatched = dispatched;
	),

	TP_printk("CFQQ max_dispatch : max dispatch : %d : dispatched : %d", __entry->max_dispatch, __entry->dispatched)

);

TRACE_EVENT(cq_flush,

	TP_PROTO(int temp),

	TP_ARGS(temp),

	TP_STRUCT__entry(
		__field(int, temp)
	),

	TP_fast_assign(
		__entry->temp = temp;
	),

	TP_printk("FlushCMD %d\n", __entry->temp)

);

TRACE_EVENT(cq_idling,

	TP_PROTO(int reason),

	TP_ARGS(reason),

	TP_STRUCT__entry(
		__field(int, reason)
	),

	TP_fast_assign(
		__entry->reason = reason;
	),

	TP_printk("CFQQ_idling: %d", __entry->reason)

);

TRACE_EVENT(cq_idling_event,

	TP_PROTO(int reason, char *eventname),

	TP_ARGS(reason, eventname),

	TP_STRUCT__entry(
		__field(int, reason)
		__field(char *, eventname)
	),

	TP_fast_assign(
		__entry->reason = reason;
		__entry->eventname = eventname;
	),

	TP_printk("CFQQ_idle: %s, %d", __entry->eventname, __entry->reason)

);

TRACE_EVENT(cq_event,

	TP_PROTO(char *text, int val),

	TP_ARGS(text, val),

	TP_STRUCT__entry(
		__field(char *, text)
		__field(int, val)
	),

	TP_fast_assign(
		__entry->text = text;
		__entry->val = val;
	),

	TP_printk("event: %s : %d", __entry->text, __entry->val)

);

TRACE_EVENT(cq_event_ul,

	TP_PROTO(char *text, unsigned long val),

	TP_ARGS(text, val),

	TP_STRUCT__entry(
		__field(char *, text)
		__field(unsigned long, val)
	),

	TP_fast_assign(
		__entry->text = text;
		__entry->val = val;
	),

	TP_printk("event: %s : %lu", __entry->text, __entry->val)

);

TRACE_EVENT(cq_reqinfo,

	TP_PROTO(int req_type, unsigned int req_size, uint64_t i2c, uint64_t d2c, int prev_read, int prev_write),

	TP_ARGS(req_type, req_size, i2c, d2c, prev_read, prev_write),

	TP_STRUCT__entry(
		__field(int, req_type)
		__field(unsigned int, req_size)
		__field(uint64_t, i2c)
		__field(uint64_t, d2c)
		__field(int, prev_read)
		__field(int, prev_write)
	),

	TP_fast_assign(
		__entry->req_type = req_type;
		__entry->req_size = req_size;
		__entry->i2c = i2c;
		__entry->d2c = d2c;
		__entry->prev_read = prev_read;
		__entry->prev_write = prev_write;
	),

	TP_printk("req: %d : size: %u : i2c: %llu : d2c: %llu : prev_read: %d : prev_write: %d", 
			__entry->req_type, __entry->req_size, __entry->i2c, __entry->d2c, __entry->prev_read, __entry->prev_write)

);

#endif /* _TRACE_CQ_H */

/* This part must be outside protection */
#include <trace/define_trace.h>

